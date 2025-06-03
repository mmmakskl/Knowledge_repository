LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY rstr_bhv IS
	PORT(
		R	: IN	std_logic;
		S	: IN	std_logic;
		Q	: OUT	std_logic;
		NQ	: OUT	std_logic
	);
END rstr_bhv;

ARCHITECTURE behav OF rstr_bhv IS
	SIGNAL QS	:	std_logic;
BEGIN
	PROCESS (S, R)
		BEGIN
			IF S = '0' THEN
				IF R = '1' THEN
					QS <= '0';
				ELSE
					QS <= QS;
				END IF;
			ELSE
				QS <= '1';
			END IF;
	END PROCESS;
	Q <= QS;
	NQ <= NOT QS;
END behav;
