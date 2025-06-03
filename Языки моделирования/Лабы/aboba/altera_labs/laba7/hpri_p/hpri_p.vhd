library IEEE;
use IEEE.std_logic_1164.all;

entity hpri_p is
port( 
	r: in std_logic_vector (7 downto 0);
	ei: in std_logic;
	eo: out std_logic;
	g: out std_logic;
	a: out std_logic_vector (2 downto 0)
	);
end hpri_p;
architecture behav of hpri_p is
begin
process (r)
begin
	if (ei = '1') then
		if (r(7) = '1') then
			a <= "111";
		elsif (r(6) = '1') then
			a <= "110";
		elsif (r(5) = '1') then
			a <= "101";
		elsif (r(4) = '1') then
			a <= "100";
		elsif (r(3) = '1') then
			a <= "011";
		elsif (r(2) = '1') then
			a <= "010";
		elsif (r(1) = '1') then
			a <= "001";
		elsif (r(0) = '1') then
			a <= "000";
		end if;
	else
		a <= "000";
	end if;
	g <= (r(0) or r(1) or r(2) or r(3) or r(4) or r(5) or r(6) or r(7)) and ei;
	eo <= (not (r(0) or r(1) or r(2) or r(3) or r(4) or r(5) or r(6) or r(7))) and ei;
end process;
end behav;