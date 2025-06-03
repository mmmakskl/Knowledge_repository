library IEEE;
use IEEE.std_logic_1164.all;

entity major_p is
port( 
	x: in std_logic_vector (3 downto 1);
	x_t: out std_logic;
	a: out std_logic_vector (1 downto 0)
	);
end major_p;

architecture behav of major_p is
begin
	x_t <= (x(1) and x(2)) or (x(1) and x(3)) or (x(2) and x(3));
	a(1) <= x(2) xor x(3);
	a(0) <= x(1) xor x(3);
end behav;