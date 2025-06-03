library ieee;
use ieee.std_logic_1164.all;

entity error_checking_s is --in std_logic_vector (7 downto 0);
port
(
	x: in std_logic_vector (7 downto 0);
	IsError: out std_logic;
	x_new: out std_logic_vector (7 downto 0)
);

end error_checking_s;



architecture behav of error_checking_s is

component eo8_p
port( 
	x: in std_logic_vector (7 downto 0);
	d: in std_logic;
	even: out std_logic;
	odd: out std_logic
	);
end component;
signal control: std_logic;
begin
	eo8_1: eo8_p port map(x, '0', control, open);
	eo8_2: eo8_p port map(
		x(7 downto 2) => x(7 downto 2), 
		x(1 downto 0) => "10",
		d => control, 
		even => IsError, 
		odd => open
		);
	x_new(7 downto 2) <= x(7 downto 2);
	x_new(1 downto 0) <= "10";
end behav;