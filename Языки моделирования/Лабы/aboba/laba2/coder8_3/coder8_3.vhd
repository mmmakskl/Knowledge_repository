LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY coder8_3 IS
	PORT (
		Y : OUT STD_LOGIC_VECTOR(2 DOWNTO 0);
		X : IN STD_LOGIC_VECTOR(7 DOWNTO 0)
	);
END coder8_3;

ARCHITECTURE coder8_3_ar OF coder8_3 IS

BEGIN
	PROCESS (X)
	BEGIN
		CASE (X) IS
			WHEN "00000001" => Y <= "000";
			WHEN "00000010" => Y <= "001";
			WHEN "00000100" => Y <= "010";
			WHEN "00001000" => Y <= "011";
			WHEN "00010000" => Y <= "100";
			WHEN "00100000" => Y <= "101";
			WHEN "01000000" => Y <= "110";
			WHEN "10000000" => Y <= "111";
			WHEN others => Y <= "000";
		END CASE;
	END PROCESS;
END coder8_3_ar;