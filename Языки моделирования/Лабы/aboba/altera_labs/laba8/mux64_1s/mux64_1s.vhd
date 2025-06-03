library ieee;
use ieee.std_logic_1164.all;

entity mux64_1s is --in std_logic_vector (7 downto 0);
port
(
	x: in std_logic_vector (63 downto 0);
	en: in std_logic;
	a: in std_logic_vector (5 downto 0);
	q: out std_logic
);

end mux64_1s;



architecture behav of mux64_1s is

component mux4_1gr
port(
	x: in std_logic_vector (3 downto 0);
	a: in std_logic_vector (1 downto 0);
	en: in std_logic;
	q: out std_logic
	);
end component;


signal a_1: std_logic_vector (16 downto 1);
signal a_2: std_logic_vector (4 downto 1);

begin
	--first level
	mux1_1: mux4_1gr port map(x(3 downto 0), a(1 downto 0), en, a_1(1));
	mux1_2: mux4_1gr port map(x(7 downto 4), a(1 downto 0), en, a_1(2));
	mux1_3: mux4_1gr port map(x(11 downto 8), a(1 downto 0), en, a_1(3));
	mux1_4: mux4_1gr port map(x(15 downto 12), a(1 downto 0), en, a_1(4));
	mux1_5: mux4_1gr port map(x(19 downto 16), a(1 downto 0), en, a_1(5));
	mux1_6: mux4_1gr port map(x(23 downto 20), a(1 downto 0), en, a_1(6));
	mux1_7: mux4_1gr port map(x(27 downto 24), a(1 downto 0), en, a_1(7));
	mux1_8: mux4_1gr port map(x(31 downto 28), a(1 downto 0), en, a_1(8));
	mux1_9: mux4_1gr port map(x(35 downto 32), a(1 downto 0), en, a_1(9));
	mux1_10: mux4_1gr port map(x(39 downto 36), a(1 downto 0), en, a_1(10));
	mux1_11: mux4_1gr port map(x(43 downto 40), a(1 downto 0), en, a_1(11));
	mux1_12: mux4_1gr port map(x(47 downto 44), a(1 downto 0), en, a_1(12));
	mux1_13: mux4_1gr port map(x(51 downto 48), a(1 downto 0), en, a_1(13));
	mux1_14: mux4_1gr port map(x(55 downto 52), a(1 downto 0), en, a_1(14));
	mux1_15: mux4_1gr port map(x(59 downto 56), a(1 downto 0), en, a_1(15));
	mux1_16: mux4_1gr port map(x(63 downto 60), a(1 downto 0), en, a_1(16));
	
	--second level
	mux2_1: mux4_1gr port map(a_1(4 downto 1), a(3 downto 2), en, a_2(1));
	mux2_2: mux4_1gr port map(a_1(8 downto 5), a(3 downto 2), en, a_2(2));
	mux2_3: mux4_1gr port map(a_1(12 downto 9), a(3 downto 2), en, a_2(3));
	mux2_4: mux4_1gr port map(a_1(16 downto 13), a(3 downto 2), en, a_2(4));
	
	--third level
	mux3_1: mux4_1gr port map(a_2, a(5 downto 4), en, q);
end behav;