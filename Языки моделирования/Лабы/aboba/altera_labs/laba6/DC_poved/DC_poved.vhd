library ieee;
use ieee.std_logic_1164.all;

entity DC_poved is
port
(
	x0: in std_logic;
	x1: in std_logic;
	x2: in std_logic;
	ENB: in std_logic;
	q0: out std_logic;
	q1: out std_logic;
	q2: out std_logic;
	q3: out std_logic;
	q4: out std_logic;
	q5: out std_logic;
	q6: out std_logic;
	q7: out std_logic
);
end DC_poved;

architecture behaviour of DC_poved is
signal p0: std_logic;
signal p1: std_logic;
signal p2: std_logic;
signal p3: std_logic;
signal p4: std_logic;
signal p5: std_logic;
signal p6: std_logic;
signal p7: std_logic;
begin
	process(x0, x1, x2, ENB)
	begin
	if (ENB = '1') then
		p0 <= '0';
		p1 <= '0';
		p2 <= '0';
		p3 <= '0';
		p4 <= '0';
		p5 <= '0';
		p6 <= '0';
		p7 <= '0';
	else
		if (x2 = '0') then
			if (x1 = '0') then
				if (x0 = '0') then -- x0 = 0 x1 = 0 x2 = 0
					p0 <= '1';
					p1 <= '0';
					p2 <= '0';
					p3 <= '0';
					p4 <= '0';
					p5 <= '0';
					p6 <= '0';
					p7 <= '0';
				else -- x0 = 0 x1 = 0 x2 = 1
					p0 <= '0';
					p1 <= '1';
					p2 <= '0';
					p3 <= '0';
					p4 <= '0';
					p5 <= '0';
					p6 <= '0';
					p7 <= '0';
				end if;
			else -- x0 = 0 x1 = 1
				if (x0 = '1') then -- x0 = 0 x1 = 1 x2 = 1
					p0 <= '0';
					p1 <= '0';
					p2 <= '0';
					p3 <= '1';
					p4 <= '0';
					p5 <= '0';
					p6 <= '0';
					p7 <= '0';
				else -- x0 = 0 x1 = 1 x2 = 0
					p0 <= '0';
					p1 <= '0';
					p2 <= '1';
					p3 <= '0';
					p4 <= '0';
					p5 <= '0';
					p6 <= '0';
					p7 <= '0';
				end if;
			end if;
		else
			if (x1 = '0') then
				if (x0 = '0') then -- x0 = 1 x1 = 0 x2 = 0
					p0 <= '0';
					p1 <= '0';
					p2 <= '0';
					p3 <= '0';
					p4 <= '1';
					p5 <= '0';
					p6 <= '0';
					p7 <= '0';
				else -- x0 = 1 x1 = 0 x2 = 1
					p0 <= '0';
					p1 <= '0';
					p2 <= '0';
					p3 <= '0';
					p4 <= '0';
					p5 <= '1';
					p6 <= '0';
					p7 <= '0';
				end if;
			else
				if (x0 = '1') then -- x0 = 1 x1 = 1 x2 = 1
					p0 <= '0';
					p1 <= '0';
					p2 <= '0';
					p3 <= '0';
					p4 <= '0';
					p5 <= '0';
					p6 <= '0';
					p7 <= '1';
				else -- x0 = 1 x1 = 1 x2 = 0
					p0 <= '0';
					p1 <= '0';
					p2 <= '0';
					p3 <= '0';
					p4 <= '0';
					p5 <= '0';
					p6 <= '1';
					p7 <= '0';
				end if;
			end if;
		end if;
	end if;
	end process;
	q0 <= p0;
	q1 <= p1;
	q2 <= p2;
	q3 <= p3;
	q4 <= p4;
	q5 <= p5;
	q6 <= p6;
	q7 <= p7;
end behaviour;