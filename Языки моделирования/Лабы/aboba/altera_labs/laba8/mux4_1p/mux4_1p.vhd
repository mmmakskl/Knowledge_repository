library IEEE;
use IEEE.std_logic_1164.all;

entity mux4_1p is
port( 
	x: in std_logic_vector (3 downto 0);
	en: in std_logic;
	a: in std_logic_vector (1 downto 0);
	q: out std_logic
	);
end mux4_1p;
architecture behav of mux4_1p is
signal t: std_logic;
begin
process (x, en, a)
begin
	if (en = '1') then
		if (a = "00") then
			t <= x(0);
		elsif (a = "01") then
			t <= x(1);
		elsif (a = "10") then
			t <= x(2);
		elsif (a = "11") then
			t <= x(3);
		end if;
	else
		t <= '0';
	end if;
	q <= t;
end process;
end behav;