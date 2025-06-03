library ieee;
use ieee.std_logic_1164.all;

entity p7_4bit2c is
port
(
	jk: in std_logic;
	c: in std_logic;
	r: in std_logic;
	q0: out std_logic;
	q1: out std_logic;
	q2: out std_logic;
	q3: out std_logic
);
end p7_4bit2c;

architecture behaviour of p7_4bit2c is
signal p0:std_logic;
signal p1:std_logic;
signal p2:std_logic;
signal p3:std_logic;
begin
	process(jk, c, r)
	begin
		if (r = '0') then
			p0 <= '0';
			p1 <= '0';
			p2 <= '0';
			p3 <= '0';
		elsif (rising_edge(c) and jk = '1') then
			if (p0 = '1') then
				if (p1 = '1') then
					if (p2 = '1') then
						if (p3 = '1') then
							p3 <= '0';
							p2 <= '0';
							p1 <= '0';
							p0 <= '0';
						else
							p3 <= '1';
							p2 <= '0';
							p1 <= '0';
							p0 <= '0';
						end if;
					else
						p2 <= '1';
						p1 <= '0';
						p0 <= '0';
					end if;
				else
					p1 <= '1';
					p0 <= '0';
				end if;
			else
				p0 <= '1';
			end if;
		end if;
	end process;
	q0 <= p0;
	q1 <= p1;
	q2 <= p2;
	q3 <= p3;
end behaviour;