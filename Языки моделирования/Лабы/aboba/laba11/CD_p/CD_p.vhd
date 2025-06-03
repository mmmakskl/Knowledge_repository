library IEEE;
use IEEE.std_logic_1164.all;

entity CD_p is
port( 
	d: in std_logic_vector (3 downto 0);
	d_o: out std_logic_vector (7 downto 0)
	);
end CD_p;
architecture behav of CD_p is
begin
process (d)
variable k1: std_logic;
variable k2: std_logic;
variable k3: std_logic;
begin
	k1 := d(0) xor d(1) xor d(3);
	k2 := d(0) xor d(2) xor d(3);
	k3 := d(1) xor d(2) xor d(3);
	d_o(0) <= k1;
	d_o(1) <= k2;
	d_o(2) <= d(0);
	d_o(3) <= k3;
	d_o(4) <= d(1);
	d_o(5) <= d(2);
	d_o(6) <= d(3);
	d_o(7) <= k1 xor k2 xor k3 xor d(0) xor d(1) xor d(2) xor d(3);
end process;
end behav;