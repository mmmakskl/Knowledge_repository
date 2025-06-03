library ieee;
use ieee.std_logic_1164.all;

entity p7_reg is
port
(
	d: in std_logic;
	c: in std_logic;
	r: in std_logic;
	d1: out std_logic;
	d2: out std_logic;
	q1: out std_logic;
	q2: out std_logic
);
end p7_reg;

architecture behaviour of p7_reg is
signal d11:std_logic;
signal d21:std_logic;
signal d31:std_logic;
begin
	process(c, r)
	begin
		if (c'EVENT and c = '1' and r = '1') then
			d11 <= d;
			d1 <= d;
			d31 <= d21;
			d2 <= d21;
		end if;
		if (c'EVENT and c = '0' and r = '1') then
			d21 <= d11;
			q1 <= d11;
			q2 <= d31;
		end if;
	end process;
end behaviour;