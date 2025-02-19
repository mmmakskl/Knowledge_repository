LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY desh6to64 IS

port (
ENN : IN std_logic;
a: in std_logic_vector (5 downto 0);
q: inout std_logic_vector (63 downto 0)
);

END desh6to64;

ARCHITECTURE behavior OF desh6to64 IS

SIGNAL qs0, qs1, qs2, qs3, qs4, qs5, qs6, qs7 : STD_LOGIC;
SIGNAL qs00, qs11, qs22, qs33, qs44, qs55, qs66, qs77 : STD_LOGIC;

COMPONENT notcomp
PORT
(
a : IN std_logic;
b : INOUT std_logic
);
END COMPONENT;

COMPONENT desh3to8
PORT
(
a0 : IN STD_LOGIC;
a1 : IN STD_LOGIC; 
a2 : IN STD_LOGIC;
EN : IN STD_LOGIC;
q0 : INOUT STD_LOGIC;
q1 : INOUT STD_LOGIC;
q2 : INOUT STD_LOGIC;
q3 : INOUT STD_LOGIC;
q4 : INOUT STD_LOGIC;
q5 : INOUT STD_LOGIC; 
q6 : INOUT STD_LOGIC;
q7 : INOUT STD_LOGIC
);
END COMPONENT;

BEGIN
dc0: desh3to8
PORT MAP (a(3), a(4), a(5), ENN, qs0, qs1,qs2, qs3, qs4, qs5, qs6, qs7);

n0: notcomp
PORT MAP (qs0, qs00);
n1: notcomp
PORT MAP (qs1, qs11);
n2: notcomp
PORT MAP (qs2, qs22);
n3: notcomp
PORT MAP (qs3, qs33);
n4: notcomp
PORT MAP (qs4, qs44);
n5: notcomp
PORT MAP (qs5, qs55);
n6: notcomp
PORT MAP (qs6, qs66);
n7: notcomp
PORT MAP (qs7, qs77);

dc1: desh3to8
PORT MAP (a(0), a(1), a(2), qs00, q(0), q(1), q(2), q(3), q(4), q(5), q(6), q(7));

dc2: desh3to8
PORT MAP (a(0), a(1), a(2), qs11, q(8), q(9), q(10), q(11), q(12), q(13), q(14), q(15));

dc3: desh3to8
PORT MAP (a(0), a(1), a(2), qs22, q(16), q(17), q(18), q(19), q(20), q(21), q(22), q(23));

dc4: desh3to8
PORT MAP (a(0), a(1), a(2), qs33, q(24), q(25), q(26), q(27), q(28), q(29), q(30), q(31));

dc5: desh3to8
PORT MAP (a(0), a(1), a(2), qs44, q(32), q(33), q(34), q(35), q(36), q(37), q(38), q(39));

dc6: desh3to8
PORT MAP (a(0), a(1), a(2), qs55, q(40), q(41), q(42), q(43), q(44), q(45), q(46), q(47));

dc7: desh3to8
PORT MAP (a(0), a(1), a(2), qs66, q(48), q(49), q(50), q(51), q(52), q(53), q(54), q(55)) ;

dc8: desh3to8
PORT MAP (a(0), a(1), a(2), qs77, q(56), q(57), q(58), q(59), q(60), q(61), q(62), q(63)) ;
END behavior;
CONFIGURATION con OF desh6to64 IS
FOR behavior
	FOR n0, n1, n2, n3, n4, n5, n6, n7: notcomp
		USE ENTITY work.notcomp(bhur);
	END FOR;
	FOR dc0, dc1, dc2, dc3, dc4, dc5, dc6, dc7, dc8: desh3to8
		USE ENTITY work.desh3to8(behav);
	END FOR;
END FOR;
END con;

