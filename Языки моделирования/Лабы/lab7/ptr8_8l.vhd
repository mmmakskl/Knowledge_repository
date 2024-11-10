library ieee;
use ieee.std_logic_1164.all;

entity ptr8_8l is
port(
	r: in std_logic_vector(7 downto 0);
	ei: in std_logic;
	q: out std_logic_vector(7 downto 0));
end ptr8_8l;

architecture behavior of ptr8_8l is
component cip8_3 is
port(
	r: in std_logic_vector(7 downto 0);
	ei: in std_logic;
	a: out std_logic_vector(2 downto 0);
	g: out std_logic;
	eo: out std_logic);
end component;
component dc3_8 is
port(
	a : in std_logic_vector(2 downto 0);
	q : out std_logic_vector(7 downto 0));
end component;
signal a: std_logic_vector(2 downto 0);
signal q_raw: std_logic_vector(7 downto 0);
signal g: std_logic;
begin
	c: cip8_3 port map(r, ei, a, g, open);
	d: dc3_8 port map(a, q_raw);
	q <= q_raw when g = '1' else "00000000";
end behavior;
configuration config of ptr8_8l is
	for behavior
		for c: cip8_3
			use entity work.cip8_3l(behavior);
		end for;
		for d: dc3_8
			use entity work.dc3s(behav);
		end for;
	end for;
end config;