LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY vhd2r1tsdvig IS
	PORT (
		d, c, r : IN STD_LOGIC;
		q2 : INOUT STD_LOGIC;
		q4 : OUT STD_LOGIC);
END vhd2r1tsdvig;
ARCHITECTURE behav OF vhd2r1tsdvig IS
	SIGNAL q1 : STD_LOGIC := '1';
	SIGNAL q3 : STD_LOGIC := '1';
BEGIN
	PROCESS (r, d, c)
	BEGIN
		IF r = '1' THEN
			IF c = '1' THEN
				q1 <= d;
				q3 <= q2;
			ELSIF c = '0' THEN
				q2 <= q1;
				q4 <= q3;
			END IF;
		ELSE
			q1 <= '0';
			q2 <= '0';
			q3 <= '0';
			q4 <= '0';
		END IF;
	END PROCESS;
END behav;
