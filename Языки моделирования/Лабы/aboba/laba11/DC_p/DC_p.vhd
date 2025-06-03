library IEEE;
use IEEE.std_logic_1164.all;

entity DC_p is
port( 
	d: in std_logic_vector (7 downto 0);
	d_o: out std_logic_vector (3 downto 0);
	ONE_ERR: out std_logic;
	DBL_ERR: out std_logic
	);
end DC_p;

architecture behav of DC_p is
signal d_ot: std_logic_vector (3 downto 0);
begin
	process (d)
	variable p1: std_logic;
	variable p2: std_logic;
	variable p3: std_logic;
	variable kp: std_logic;
	variable d_otv: std_logic_vector (3 downto 0);
	begin
		kp := '0';
		p1 := d(0) xor d(2) xor d(4) xor d(6);
		p2 := d(1) xor d(2) xor d(5) xor d(6);
		p3 := d(3) xor d(4) xor d(5) xor d(6);
		for i in 0 to 7 loop
			kp := kp xor d(i);
		end loop;
		d_otv(0) := d(2);
		d_otv(1) := d(4);
		d_otv(2) := d(5);
		d_otv(3) := d(6);
		if kp = '1' then
			if p1 = '1' and p2 = '1' and p3 = '0' then
				d_otv(0) := not d(2);
			elsif p1 = '1' and p2 = '0' and p3 = '1' then
				d_otv(1) := not d(4);
			elsif p1 = '0' and p2 = '1' and p3 = '1' then
				d_otv(2) := not d(5);
			elsif p1 = '1' and p2 = '1' and p3 = '1' then
				d_otv(3) := not d(6);
			end if;
		end if;
		ONE_ERR <= kp;
		DBL_ERR <= (not kp) and (p1 or p2 or p3);
		d_ot <= d_otv;
	end process;
	d_o <= d_ot;
end behav;