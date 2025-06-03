library ieee;
use ieee.std_logic_1164.all;

entity double_coder_s is --in std_logic_vector (7 downto 0);
port
(
	x: in std_logic_vector (63 downto 0);
	a: out std_logic_vector (5 downto 0);
	g: out std_logic
);

end double_coder_s;



architecture behav of double_coder_s is

component hpri
port(
	r: in std_logic_vector (7 downto 0);
	ei: in std_logic;
	a: out std_logic_vector (2 downto 0);
	eo: out std_logic;
	g: out std_logic
	);
end component;

component or_8
port(
	x0: in std_logic;
	x1: in std_logic;
	x2: in std_logic;
	x3: in std_logic;
	x4: in std_logic;
	x5: in std_logic;
	x6: in std_logic;
	x7: in std_logic;
	q: out std_logic
	);
end component;

signal a_1: std_logic_vector (2 downto 0);
signal a_2: std_logic_vector (2 downto 0);
signal a_3: std_logic_vector (2 downto 0);
signal a_4: std_logic_vector (2 downto 0);
signal a_5: std_logic_vector (2 downto 0);
signal a_6: std_logic_vector (2 downto 0);
signal a_7: std_logic_vector (2 downto 0);
signal a_8: std_logic_vector (2 downto 0);
signal ens: std_logic_vector (8 downto 2);
signal gs: std_logic_vector (8 downto 1);

begin
hpri1: hpri port map(x(7 downto 0), ens(2), a_1, open, gs(1));
hpri2: hpri port map(x(15 downto 8), ens(3), a_2, ens(2), gs(2));
hpri3: hpri port map(x(23 downto 16), ens(4), a_3, ens(3), gs(3));
hpri4: hpri port map(x(31 downto 24), ens(5), a_4, ens(4), gs(4));
hpri5: hpri port map(x(39 downto 32), ens(6), a_5, ens(5), gs(5));
hpri6: hpri port map(x(47 downto 40), ens(7), a_6, ens(6), gs(6));
hpri7: hpri port map(x(55 downto 48), ens(8), a_7, ens(7), gs(7));
hpri8: hpri port map(x(63 downto 56), '1', a_8, ens(8), gs(8));
hpri9: hpri port map(gs(8 downto 1), '1', a(5 downto 3), open, g);
or0: or_8 port map(a_1(0), a_2(0), a_3(0), a_4(0), a_5(0), a_6(0), a_7(0), a_8(0), a(0));
or1: or_8 port map(a_1(1), a_2(1), a_3(1), a_4(1), a_5(1), a_6(1), a_7(1), a_8(1), a(1));
or2: or_8 port map(a_1(2), a_2(2), a_3(2), a_4(2), a_5(2), a_6(2), a_7(2), a_8(2), a(2));
end behav;