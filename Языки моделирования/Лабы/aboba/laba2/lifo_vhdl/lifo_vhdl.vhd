LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY lifo_vhdl IS
	PORT (
		I_DATA : IN STD_LOGIC_VECTOR(7 DOWNTO 0); --Input Data Line
		O_DATA : OUT STD_LOGIC_VECTOR(7 DOWNTO 0); --Output Data Line
		I_RD_WR : IN STD_LOGIC; --Input RD/~WR signal. 1 for READ, 0 for Write
		O_FULL : OUT STD_LOGIC; --Output Full signal. 1 when memory is full.
		O_EMPTY : OUT STD_LOGIC; --Output Empty signal. 1 when memory is empty.
		clk : IN STD_LOGIC;
		rst : IN STD_LOGIC
	);
END ENTITY lifo_vhdl;

ARCHITECTURE RTL OF lifo_vhdl IS
	-- Helper Function to convert Boolean to Std_logic
	FUNCTION to_std_logic(B : BOOLEAN) RETURN STD_LOGIC IS
	BEGIN
		IF B = false THEN
			RETURN '0';
		ELSE
			RETURN '1';
		END IF;
	END FUNCTION to_std_logic;

	TYPE memory_type IS ARRAY (0 TO 7) OF STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL memory : memory_type;
BEGIN
	main : PROCESS (clk, rst) IS
		VARIABLE stack_pointer : INTEGER RANGE 0 TO 7 := 0;
		VARIABLE count_of_elems : INTEGER RANGE 0 TO 8 := 0;
		VARIABLE EMPTY, FULL : BOOLEAN := false;
	BEGIN
		--Async Reset
		IF rst = '1' THEN
			memory <= (OTHERS => (OTHERS => '0'));
			EMPTY := true;
			FULL := false;
			stack_pointer := 0;

		ELSIF rising_edge(clk) THEN
			IF I_RD_WR = '1' THEN
				IF count_of_elems /= 0 THEN
					IF count_of_elems = 1 THEN
						O_DATA <= memory(0);
					ELSE
						O_DATA <= memory(stack_pointer);
						stack_pointer := stack_pointer - 1;
					END IF;
					count_of_elems := count_of_elems - 1;
				END IF;
			ELSE
				IF count_of_elems /= 0 AND count_of_elems /= 8 THEN
					stack_pointer := stack_pointer + 1;
				END IF;
				memory(stack_pointer) <= I_DATA;
				count_of_elems := count_of_elems + 1;
			END IF;

			-- Check for Empty
			IF count_of_elems = 0 THEN
				EMPTY := true;
			ELSE
				EMPTY := false;
			END IF;

			-- Check for Full
			IF count_of_elems = 8 THEN
				FULL := true;
			ELSE
				FULL := false;
			END IF;
		END IF;
		O_FULL <= to_std_logic(FULL);
		O_EMPTY <= to_std_logic(EMPTY);
	END PROCESS main;

END ARCHITECTURE RTL;