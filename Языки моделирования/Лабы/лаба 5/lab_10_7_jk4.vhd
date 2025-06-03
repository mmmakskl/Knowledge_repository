library ieee;
use ieee.std_logic_1164.all;

entity lab_10_7_jk4 is
	port(
		c, r, jk : IN std_logic;
		q0, q1, q2, q3 : out std_logic);
end lab_10_7_jk4;

architecture behav of lab_10_7_jk4 is
	signal t0, t1, t2, t3 : std_logic;
begin
	process(c, r, jk)begin
		if(r = '0')then
			t0 <= '0';
			t1 <= '0';
			t2 <= '0';
			t3 <= '0';
		elsif(c'event and c = '1')then
			if(jk = '1')then
				if(t0 = '0')then
					t0 <= '1';
				elsif(t1 = '0')then
					t0 <= '0';
					t1 <= '1';
				elsif(t2 = '0')then
					t0 <= '0';
					t1 <= '0';
					t2 <= '1';
				elsif(t3 = '0')then
					t0 <= '0';
					t1 <= '0';
					t2 <= '0';
					t3 <= '1';
				else
					t0 <= '0';
					t1 <= '0';
					t2 <= '0';
					t3 <= '0';
				end if;
			end if;
		end if;
	end process;

q0 <= t0;
q1 <= t1;
q2 <= t2;
q3 <= t3;
end behav;
