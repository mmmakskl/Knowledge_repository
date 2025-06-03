library ieee;
use ieee.std_logic_1164.all;

entity 2bitshregvhdl_p is
port
(
	d: in std_logic;
	c1: in std_logic;
	c2: in std_logic;
	r: in std_logic;
	q1: out std_logic;
	q2: out std_logic;
);
end dtr_p;

architecture behaviour of 2bitshregvhdl_p is
signal d11:std_logic;
signal d21:std_logic;
begin
	process(c1,c2,r)
	begin
		if (c1'event and c1 = '1' and r)
			d11 <= d;
			d21 <= q1;
		end if;
		if (c2'event and c2 = '1' and r)
			q1 <= d11;
			q2 <= d21;
		end if;
	end process;
end behaviour;
