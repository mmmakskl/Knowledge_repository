library IEEE;
use IEEE.std_logic_1164.all;

entity pointer_vhdl is
port( 
	r: in std_logic_vector (7 downto 0);
	ei: in std_logic;
	a: out std_logic_vector (7 downto 0)
	);
end pointer_vhdl;

architecture behav of pointer_vhdl is
begin
process (r)
begin
	if (ei = '1') then
		if (r(7) = '1') then
			a <= "10000000";
		elsif (r(6) = '1') then
			a <= "01000000";
		elsif (r(5) = '1') then
			a <= "00100000";
		elsif (r(4) = '1') then
			a <= "00010000";
		elsif (r(3) = '1') then
			a <= "00001000";
		elsif (r(2) = '1') then
			a <= "00000100";
		elsif (r(1) = '1') then
			a <= "00000010";
		elsif (r(0) = '1') then
			a <= "00000001";
		end if;
	else
		a <= "00000000";
	end if;
end process;
end behav;