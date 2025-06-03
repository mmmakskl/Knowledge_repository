LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY rstr_s IS
PORT( s : IN std_logic;
 r : IN std_logic;
 q : INOUT std_logic;
 qb : INOUT std_logic );
END rstr_s;
ARCHITECTURE behav OF rstr_s IS
COMPONENT notand
PORT( a : IN std_logic;
 b : IN std_logic;
 c : INOUT std_logic);
END COMPONENT;
BEGIN
u1: notand
 PORT MAP ( s, qb, q);
u2: notand
 PORT MAP (q, r, qb);
END behav;
CONFIGURATION con OF rstr_s IS
 FOR behav
 FOR u1, u2: notand
 USE ENTITY work.notand(behavior);
END FOR;
END FOR;
END con;
