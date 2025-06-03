library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity cache is
    generic (
        CACHE_SIZE : integer := 4;
        ADDR_WIDTH : integer := 8;
        DATA_WIDTH : integer := 8;
        RAM_SIZE   : integer := 16
    );
    port (
        clk       : in std_logic;
        reset     : in std_logic;
        read_en   : in std_logic;
        write_en  : in std_logic;
        addr      : in std_logic_vector(ADDR_WIDTH-1 downto 0);
        data_in   : in std_logic_vector(DATA_WIDTH-1 downto 0);
        data_out  : out std_logic_vector(DATA_WIDTH-1 downto 0);
        hit       : buffer std_logic
    );
end cache;

architecture bhv of cache is
    type cache_entry is record
        valid : std_logic;
        tag   : std_logic_vector(ADDR_WIDTH-1 downto 0);
        data  : std_logic_vector(DATA_WIDTH-1 downto 0);
    end record;
    
    type cache_array is array (0 to CACHE_SIZE-1) of cache_entry;
    signal cache : cache_array := (others => ('0', (others => '0'), (others => '0')));

    type RAM_Array is array (0 to RAM_SIZE-1) of std_logic_vector(DATA_WIDTH-1 downto 0);
    signal ram : RAM_Array := (others => (others => '0'));

    signal lru_counter : integer range 0 to CACHE_SIZE-1 := 0;
begin
	process (clk, reset)
	    variable temp_data : std_logic_vector(DATA_WIDTH-1 downto 0);
	    variable found : std_logic;
	    variable cache_index : integer range 0 to CACHE_SIZE-1;
	begin
	    if reset = '1' then
	        cache <= (others => ('0', (others => '0'), (others => '0')));
	        ram <= (others => (others => '0'));
	        hit <= '0';
	        data_out <= (others => '0');
	    elsif rising_edge(clk) then
	        found := '0';
	        cache_index := 0;

	        for i in 0 to CACHE_SIZE-1 loop
	            if cache(i).valid = '1' and cache(i).tag = addr then
	                cache_index := i;
	                found := '1';
	            end if;
	        end loop;

	        if write_en = '1' then
	            ram(conv_integer(addr)) <= data_in;
	            if found = '1' then
	                cache(cache_index).data <= data_in;
	            else
	                cache(lru_counter) <= ('1', addr, data_in);
	                lru_counter <= (lru_counter + 1) mod CACHE_SIZE;
	            end if;
	            hit <= found;
	        elsif read_en = '1' then
	            if found = '1' then
	                temp_data := cache(cache_index).data;
	            else
	                temp_data := ram(conv_integer(addr));
	                cache(lru_counter) <= ('1', addr, temp_data);
	                lru_counter <= (lru_counter + 1) mod CACHE_SIZE;
	            end if;
	            data_out <= temp_data;
	            hit <= found;
	        else
	            data_out <= (others => '0');
	        end if;
	    end if;
	end process;
end bhv;
