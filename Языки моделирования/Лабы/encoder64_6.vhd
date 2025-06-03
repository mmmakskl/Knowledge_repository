library ieee;use ieee.std_logic_1164.all;
entity encoder64_6 is
port (
ENABLE : in std_logic;G : inout std_logic;
r : in std_logic_vector( 63 downto 0);a : inout std_logic_vector(5 downto 0)
);end encoder64_6;
architecture behavior of encoder64_6 is
signal eo0, eo1, eo2, eo3, eo4, eo5, eo6, eo7 : std_logic;
signal g0, g1, g2, g3, g4, g5, g6, g7 : std_logic;
signal a10, a11, a12, a13, a14, a15, a16, a17 : std_logic;signal a20, a21, a22, a23, a24, a25, a26, a27 : std_logic;
signal a00, a01, a02, a03, a04, a05, a06, a07 : std_logic;
component notand_4 port
(a0, a1, a2, a3 : in std_logic;
b : inout std_logic);
end component;
component notor_8 port
(a0, a1, a2, a3, a4, a5, a6, a7 : in std_logic;
b : inout std_logic);
end component;
component or_8 port
(a0, a1, a2, a3, a4, a5, a6, a7 : in std_logic;
b : inout std_logic);
end component;
component encoder8_3 port ( r0, r1, r2, r3, r4, r5, r6, r7, EI : in std_logic;
 an_0, an_1, an_2, EO, G : inout std_logic);end component;
begin
c7 : encoder8_3
port map(r(56), r(57), r(58), r(59), r(60), r(61), r(62), r(63), ENABLE, a07, a17, a27, eo7, g7);
c6 : encoder8_3 portmap(r(48), r(49), r(50), r(51), r(52), r(53), r(54), r(55), eo7, a06, a16, a26, eo6, g6);
c5 : encoder8_3
port map(r(40), r(41), r(42), r(43), r(44), r(45), r(46), r(47), eo6, a05, a15, a25, eo5, g5);
c4 : encoder8_3 port map(r(32), r(33), r(34), r(35), r(36), r(37), r(38), r(39), eo5, a04, a14, a24, eo4, g4);

c3 : encoder8_3 port map(r(24), r(25), r(26), r(27), r(28), r(29), r(30), r(31), eo4, a03, a13, a23, eo3, g3);
c2 : encoder8_3
port map(r(16), r(17), r(18), r(19), r(20), r(21), r(22), r(23), eo3, a02, a12, a22, eo2, g2);
c1 : encoder8_3 port map(r(8), r(9), r(10), r(11), r(12), r(13), r(14), r(15), eo2, a01, a11, a21, eo1, g1);
c0 : encoder8_3
port map(r(0), r(1), r(2), r(3), r(4), r(5), r(6), r(7), eo1, a00, a10, a20, eo0, g0);

nand1: notand_4 port map(eo7, eo6, eo5, eo4, a(5));
nand2: notand_4
port map(eo7, eo6, eo3, eo2, a(4));
nand3: notand_4 port map(eo7, eo5, eo3, eo1, a(3));

or1: or_8 port map(a00, a01, a02, a03, a04, a05, a06, a07, a(0));
or2: or_8
port map(a10, a11, a12, a13, a14, a15, a16, a17, a(1));
or3: or_8
port map(a20, a21, a22, a23, a24, a25, a26, a27, a(2));
or4: or_8 port map(g0, g1, g2, g3, g4, g5, g6, g7, G);
end behavior;
configuration con of encoder64_6 is
for behavior for c7, c6, c5, c4, c3, c2, c1, c0 : encoder8_3
  use entity work.encoder8_3(bhvr); end for;
  for nand3, nand2, nand1 : notand_4
  use entity work.notand_4(behav); end for;
 for or1, or2, or3, or4 : or_8
  use entity work.or_8(behavi); end for;
end for;end con;
