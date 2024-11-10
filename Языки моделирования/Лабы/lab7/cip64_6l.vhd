library ieee;
use ieee.std_logic_1164.all;

entity cip64_6l is
port(
	r: in std_logic_vector(63 downto 0);
	ei: in std_logic;
	a: out std_logic_vector(5 downto 0);
	g: out std_logic;
	eo: out std_logic);
end cip64_6l;

architecture behavior of cip64_6l is
component cip8_3 is
port(
	r: in std_logic_vector(7 downto 0);
	ei: in std_logic;
	a: out std_logic_vector(2 downto 0);
	g: out std_logic;
	eo: out std_logic);
end component;

signal a1_1: std_logic_vector(2 downto 0);
signal a1_2: std_logic_vector(2 downto 0);
signal a1_3: std_logic_vector(2 downto 0);
signal a1_4: std_logic_vector(2 downto 0);
signal a1_5: std_logic_vector(2 downto 0);
signal a1_6: std_logic_vector(2 downto 0);
signal a1_7: std_logic_vector(2 downto 0);
signal a1_8: std_logic_vector(2 downto 0);

signal a2_1: std_logic_vector(3 downto 0);
signal a2_2: std_logic_vector(3 downto 0);
signal a2_3: std_logic_vector(3 downto 0);
signal a2_4: std_logic_vector(3 downto 0);

signal a3_1: std_logic_vector(4 downto 0);
signal a3_2: std_logic_vector(4 downto 0);

signal a4_1: std_logic_vector(5 downto 0);

signal g1_1: std_logic;
signal g1_2: std_logic;
signal g1_3: std_logic;
signal g1_4: std_logic;
signal g1_5: std_logic;
signal g1_6: std_logic;
signal g1_7: std_logic;
signal g1_8: std_logic;

signal g2_1: std_logic;
signal g2_2: std_logic;
signal g2_3: std_logic;
signal g2_4: std_logic;

signal g3_1: std_logic;
signal g3_2: std_logic;

signal g4_1: std_logic;

signal eo1_1: std_logic;
signal eo1_2: std_logic;
signal eo1_3: std_logic;
signal eo1_4: std_logic;
signal eo1_5: std_logic;
signal eo1_6: std_logic;
signal eo1_7: std_logic;
signal eo1_8: std_logic;

signal ei2_1: std_logic;
signal ei2_2: std_logic;

signal ei3_1: std_logic;

begin
	c1: cip8_3 port map(  r(7 downto 0), eo1_2, a1_1, g1_1, eo1_1);
	c2: cip8_3 port map( r(15 downto 8), ei2_1, a1_2, g1_2, eo1_2);
	c3: cip8_3 port map(r(23 downto 16), eo1_4, a1_3, g1_3, eo1_3);
	c4: cip8_3 port map(r(31 downto 24), ei3_1, a1_4, g1_4, eo1_4);
	c5: cip8_3 port map(r(39 downto 32), eo1_6, a1_5, g1_5, eo1_5);
	c6: cip8_3 port map(r(47 downto 40), ei2_2, a1_6, g1_6, eo1_6);
	c7: cip8_3 port map(r(55 downto 48), eo1_8, a1_7, g1_7, eo1_7);
	c8: cip8_3 port map(r(63 downto 56),    ei, a1_8, g1_8, eo1_8);

	a2_1 <= g1_2 & a1_1 or a1_2;
	a2_2 <= g1_4 & a1_3 or a1_4;
	a2_3 <= g1_6 & a1_5 or a1_6;
	a2_4 <= g1_8 & a1_7 or a1_8;
	
	a3_1 <= g2_2 & a2_1 or a2_2;
	a3_2 <= g2_4 & a2_3 or a2_4;
	
	a4_1 <= g3_2 & a3_1 or a3_2;
	
	g2_1 <= g1_1 or g1_2;
	g2_2 <= g1_3 or g1_4;
	g2_3 <= g1_5 or g1_6;
	g2_4 <= g1_7 or g1_8;
	
	g3_1 <= g2_1 or g2_2;
	g3_2 <= g2_3 or g2_4;
	
	g4_1 <= g3_1 or g3_2;
	
	ei2_1 <= ei and not g2_2;
	ei2_2 <= ei and not g2_4;
	
	ei3_1 <= ei and not g3_2;
	
	a <= a4_1;
	g <= g4_1;
	eo <= not g4_1;
end behavior;
configuration config of cip64_6l is
	for behavior
		for c1, c2, c3, c4, c5, c6, c7, c8: cip8_3
			use entity work.cip8_3l(behavior);
		end for;
	end for;
end config;