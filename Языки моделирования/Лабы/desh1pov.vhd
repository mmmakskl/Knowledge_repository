-- MAX+plus II VHDL Template
-- Clearable flipflop with enable

LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY desh1pov IS
	PORT
	(
		en	: IN	STD_LOGIC;
		a0	: IN	STD_LOGIC;
		a1	: IN	STD_LOGIC;
		a2	: IN	STD_LOGIC;
		q0	: OUT 	STD_LOGIC;
		q1	: OUT 	STD_LOGIC;
		q2	: OUT 	STD_LOGIC;
		q3	: OUT 	STD_LOGIC;
		q4	: OUT 	STD_LOGIC;
		q5	: OUT 	STD_LOGIC;
		q6	: OUT 	STD_LOGIC;
		q7	: OUT 	STD_LOGIC
	);
END desh1pov;

ARCHITECTURE a OF desh1pov IS
	SIGNAL	qs0	: STD_LOGIC;
	SIGNAL	qs1	: STD_LOGIC;
	SIGNAL	qs2	: STD_LOGIC;
	SIGNAL	qs3	: STD_LOGIC;
	SIGNAL	qs4	: STD_LOGIC;
	SIGNAL	qs5	: STD_LOGIC;
	SIGNAL	qs6	: STD_LOGIC;
	SIGNAL	qs7	: STD_LOGIC;
BEGIN
	PROCESS (en, a0, a1, a2, qs0, qs1, qs2, qs3, qs4, qs5, qs6, qs7)
	BEGIN
		IF en = '0' THEN
			qs0 <= '1';
			qs1 <= '1';
			qs2 <= '1';
			qs3 <= '1';
			qs4 <= '1';
			qs5 <= '1';
			qs6 <= '1';
			qs7 <= '1';
		ELSIF (a0 = '0' AND a1 = '0' AND a2 = '0') THEN
			qs0 <= '0';
			qs1 <= '1';
			qs2 <= '1';
			qs3 <= '1';
			qs4 <= '1';
			qs5 <= '1';
			qs6 <= '1';
			qs7 <= '1';
		ELSIF (a0 = '1' AND a1 = '0' AND a2 = '0') THEN
			qs0 <= '1';
			qs1 <= '0';
			qs2 <= '1';
			qs3 <= '1';
			qs4 <= '1';
			qs5 <= '1';
			qs6 <= '1';
			qs7 <= '1';
		ELSIF (a0 = '0' AND a1 = '1' AND a2 = '0') THEN
			qs0 <= '1';
			qs1 <= '1';
			qs2 <= '0';
			qs3 <= '1';
			qs4 <= '1';
			qs5 <= '1';
			qs6 <= '1';
			qs7 <= '1';
		ELSIF (a0 = '0' AND a1 = '0' AND a2 = '1') THEN
			qs0 <= '1';
			qs1 <= '1';
			qs2 <= '1';
			qs3 <= '1';
			qs4 <= '0';
			qs5 <= '1';
			qs6 <= '1';
			qs7 <= '1';
		ELSIF (a0 = '1' AND a1 = '1' AND a2 = '0') THEN
			qs0 <= '1';
			qs1 <= '1';
			qs2 <= '1';
			qs3 <= '0';
			qs4 <= '1';
			qs5 <= '1';
			qs6 <= '1';
			qs7 <= '1';
		ELSIF (a0 = '1' AND a1 = '0' AND a2 = '1') THEN
			qs0 <= '1';
			qs1 <= '1';
			qs2 <= '1';
			qs3 <= '1';
			qs4 <= '1';
			qs5 <= '0';
			qs6 <= '1';
			qs7 <= '1';
		ELSIF (a0 = '0' AND a1 = '1' AND a2 = '1') THEN
			qs0 <= '1';
			qs1 <= '1';
			qs2 <= '1';
			qs3 <= '1';
			qs4 <= '1';
			qs5 <= '1';
			qs6 <= '0';
			qs7 <= '1';
		ELSIF (a0 = '1' AND a1 = '1' AND a2 = '1') THEN
			qs0 <= '1';
			qs1 <= '1';
			qs2 <= '1';
			qs3 <= '1';
			qs4 <= '1';
			qs5 <= '1';
			qs6 <= '1';
			qs7 <= '0';
		END IF;
	END PROCESS;
	q0 <= qs0;
	q1 <= qs1;
	q2 <= qs2;
	q3 <= qs3;
	q4 <= qs4;
	q5 <= qs5;
	q6 <= qs6;
	q7 <= qs7;
END a;

