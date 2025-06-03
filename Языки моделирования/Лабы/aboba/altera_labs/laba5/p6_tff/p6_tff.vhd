library ieee;
use ieee.std_logic_1164.all;

entity p6_tff is
port
(
	t: in std_logic;
	q: out std_logic
);
end p6_tff;

architecture behaviour of p6_tff is
signal p:std_logic;
begin
	process(t)
	begin
		if (rising_edge(t)) then
			p <= not p;
		end if;
	end process;
	q <= p;
end behaviour;