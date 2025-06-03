library IEEE;
use IEEE.std_logic_1164.all;

entity eo8_p is
port( 
	x: in std_logic_vector (7 downto 0);
	d: in std_logic;
	even: out std_logic;
	odd: out std_logic
	);
end eo8_p;
architecture behav of eo8_p is
begin
process (x, d)
variable even_v: std_logic;
begin
	even_v := '0';
	for k in 0 to x'length-1 loop
      even_v := even_v xor x(k);
    end loop;
	even_v := even_v xor d;
	even_v := not even_v;
	even <= even_v;
	odd <= not even_v;
end process;
end behav;