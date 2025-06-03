library IEEE;
use IEEE.std_logic_1164.all;

entity cmp_p is
port( 
	x, y: in std_logic_vector (1 downto 0);
	xgy0: in std_logic;
	xly0: in std_logic;
	xey0: in std_logic;
	xgy: out std_logic;
	xly: out std_logic;
	xey: out std_logic
	);
end cmp_p;
architecture behav of cmp_p is
signal xey_t: std_logic;
signal xgy_t: std_logic;
signal xly_t: std_logic;
begin
process (x, y, xgy0, xly0, xey0)
variable eq1: std_logic;
variable eq0: std_logic;
variable eq: std_logic;
variable gr: std_logic;
variable ls: std_logic;
begin
	eq1 := not (x(1) xor y(1));
	eq0 := not (x(0) xor y(0));
	eq := eq0 and eq1;
	gr := (x(1) and not y(1)) or (eq1 and x(0) and not y(0));
	ls := (not gr) and (not eq);
	xey_t <= eq and xey0;
	xgy_t <= (gr or (eq and xgy0));
	xly_t <= (ls or (eq and xly0));
end process;
xey <= xey_t;
xgy <= xgy_t;
xly <= xly_t;
end behav;