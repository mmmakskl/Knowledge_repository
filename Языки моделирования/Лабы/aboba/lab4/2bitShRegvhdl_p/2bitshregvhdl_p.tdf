library ieee;
use ieee.std_logic_1164.all;

entity dtr_p is
port
(
	d: in std_logic;
	l: in std_logic;
	q: out std_logic;
	qb: out std_logic
);
end dtr_p;

architecture behaviour of dtr_p is
signal qs:std_logic;
begin
	process(d,l)
	begin
		if l = '1' then
			if d = '0' then
				qs <= '0';
			else
				qs <= '1';
			end if;
		else
			qs <= qs;
		end if;
	end process;
	q <= qs;
	qb <= not qs;
end behaviour;
