library IEEE;
use IEEE.std_logic_1164.all;

entity dmx_p is
port( 
	e: in std_logic;
	x: in std_logic_vector (1 downto 0);
	f: out std_logic_vector (3 downto 0)
	);
end dmx_p;
architecture behav of dmx_p is
begin
process (x, e)
begin
	if (x = "00") then
		f(0) <= e;
		f(3 downto 1) <= "000";
	elsif (x = "01") then
		f(0) <= '0';
		f(1) <=  e;
		f(3 downto 2) <= "00";
	elsif (x = "10") then
		f(1 downto 0) <= "00";
		f(2) <=  e;
		f(3) <= '0';
	elsif (x = "11") then
		f(2 downto 0) <= "000";
		f(3) <= e;
	end if;
end process;
end behav;