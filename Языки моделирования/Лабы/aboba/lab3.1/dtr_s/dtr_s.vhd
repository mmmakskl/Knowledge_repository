library ieee;
use ieee.std_logic_1164.all;

entity dtr_s is 
port
(
  d: in std_logic;
  l: in std_logic;
  s: inout std_logic;
  r: inout std_logic;
  q: out std_logic;
  qb: out std_logic
);
end dtr_s;

architecture behaviour of dtr_s is
component notand
port
(
      a: in std_logic;
      b: in std_logic;
      c: inout std_logic
);
end component;
component rstr_s
port
(
	s: in std_logic;
	r: in std_logic;
	q: out std_logic;
	qb: out std_logic
);
end component;
begin
	n1: notand
	port map(d,l,s);
	n2: notand
	port map(l,s,r);
	rs: rstr_s
	port map(s, r, q, qb);
end behaviour;
configuration con of dtr_s is
for behaviour
	for rs: rstr_s
		use entity work.rstr_s(behaviour);
	end for;
	for n1, n2: notand
		use entity work.notand(behaviour);
	end for;

end for;
end con;

