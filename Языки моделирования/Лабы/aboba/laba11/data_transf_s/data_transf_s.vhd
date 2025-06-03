library ieee;
use ieee.std_logic_1164.all;

entity data_transf_s is
port
(
	d: in std_logic_vector (3 downto 0);
	err: in std_logic_vector (3 downto 0);
	d_o: out std_logic_vector (3 downto 0);
	ONE_ERR: out std_logic;
	DBL_ERR: out std_logic
);

end data_transf_s;



architecture behav of data_transf_s is

component CD_p is
port( 
	d: in std_logic_vector (3 downto 0);
	d_o: out std_logic_vector (7 downto 0)
	);
end component;

component DC_p is
port( 
	d: in std_logic_vector (7 downto 0);
	d_o: out std_logic_vector (3 downto 0);
	ONE_ERR: out std_logic;
	DBL_ERR: out std_logic
	);
end component;
signal d_t: std_logic_vector(7 downto 0);
begin
	cd: CD_p port map(d, d_t);
	dc: DC_p port map(
		d(7) => d_t(7),
		d(6 downto 4) =>  d_t(6 downto 4) xor err(3 downto 1),
		d(3) => d_t(3),
		d(2) => d_t(2) xor err(0),
		d(1 downto 0) => d_t(1 downto 0),
		d_o => d_o,
		ONE_ERR => ONE_ERR,
		DBL_ERR => DBL_ERR
	);
end behav;