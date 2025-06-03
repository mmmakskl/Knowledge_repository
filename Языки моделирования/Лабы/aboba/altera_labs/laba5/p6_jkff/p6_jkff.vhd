LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

entity p6_jkff is
port( 
	j, k: in std_logic;
	q: out std_logic);
end p6_jkff;

architecture behav of p6_jkff is
signal s,s1: std_logic;
begin
	process(j,k)
		begin
		if (k='0' and j='0') then
			s<=s;
			s1<=s1;
		elsif(k='0' and j='1') then
			s<='1';
			s1<=s;
		elsif (k='1' and j='0') then
			s<='0';
			s1<=s;
		elsif (k='1' and j='1') then
			if(s1='0') then
				s<='1';
			elsif (s1='1') then
				s<='0';
			end if;
		end if;
	end process;
	q<=s;
end behav;