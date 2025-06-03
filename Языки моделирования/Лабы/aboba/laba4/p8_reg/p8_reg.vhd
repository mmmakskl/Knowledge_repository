library ieee;
use ieee.std_logic_1164.all;

entity p8_reg is
port
(
	d: in std_logic;
	c1: in std_logic;
	c2: in std_logic;
	r: in std_logic;
	ex1: out std_logic;
	ex2: out std_logic;
	q1: out std_logic;
	q2: out std_logic
);
end p8_reg;

architecture behaviour of p8_reg is
signal d11:std_logic;
signal d21:std_logic;
signal d31:std_logic;
begin
	process(c1,c2,r)
	begin
		if (c1'EVENT and c1 = '1' and r = '1') then
			d11 <= d;
			d31 <= d21;
			ex1 <= d;
			ex2 <= d21;
		end if;
		if (c2'EVENT and c2 = '1' and r = '1') then
			d21 <= d11;
			q1 <= d11;
			q2 <= d31;
		end if;
	end process;
end behaviour;