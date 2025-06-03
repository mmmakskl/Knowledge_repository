library ieee;
use ieee.std_logic_1164.all;

entity cmp4_s is --in std_logic_vector (7 downto 0);
port
(
	x, y: in std_logic_vector (3 downto 0);
	xgy0: in std_logic;
	xly0: in std_logic;
	xey0: in std_logic;
	xgy: out std_logic;
	xly: out std_logic;
	xey: out std_logic
);

end cmp4_s;



architecture behav of cmp4_s is

component cmp_p
port( 
	x, y: in std_logic_vector (1 downto 0);
	xgy0: in std_logic;
	xly0: in std_logic;
	xey0: in std_logic;
	xgy: out std_logic;
	xly: out std_logic;
	xey: out std_logic
	);
end component;


signal xgy_t: std_logic;
signal xly_t: std_logic;
signal xey_t: std_logic;

begin
	cmp_1: cmp_p port map(x(1 downto 0), y(1 downto 0), xgy0, xly0, xey0, xgy_t, xly_t, xey_t);
	cmp_2: cmp_p port map(x(3 downto 2), y(3 downto 2), xgy_t, xly_t, xey_t, xgy, xly, xey);
end behav;