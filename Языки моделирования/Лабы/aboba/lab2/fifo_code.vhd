library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity fifo_code is
	port (DI : in std_logic_vector(7 downto 0);
		 WR,RD, Reset: in std_logic;
   	     DO : out std_logic_vector(7 downto 0);
		  full, empty : out std_logic);
end fifo_code;

architecture behav of fifo_code is
type wordsArray is array (0 to 7) of std_logic_vector(7 downto 0);
signal outWord : std_logic_vector(7 downto 0);
signal words : wordsArray;
signal tmp : wordsArray;
signal tmpClock : std_logic;
signal isEmpty : std_logic;
signal isFull : std_logic;
begin
	tmpClock <= WR or RD;
    process(tmpClock, reset)
    variable wrCounter : integer range 0 to 7 := 0;
    variable rdCounter : integer range 0 to 7 := 0;
	begin
    if(Reset = '1') then
      wrCounter := 0;
      rdCounter := 0;
    else
    	if tmpClock = true then
    	if(WR = '1') then
        	words(wrCounter) <= DI;
        	wrCounter := wrCounter + 1;
        	if(wrCounter > 7) then
          		wrCounter := 0;
        	end if;
        	if(wrCounter = rdCounter) then
        		isFull <= '1';
        		isEmpty <= '0';
        	else
        		isFull <= '0';
        		isEmpty <= '0';
        	end if;
      	end if;
   		if(RD = '1') then 
       		outWord <= words(rdCounter);
       		rdCounter := rdCounter + 1;
       		if(rdCounter > 7) then
         		rdCounter := 0;
       		end if;
       		if(wrCounter = rdCounter) then
        		isEmpty <= '1';
        		isFull <= '0';
        	else
        		isEmpty <= '0';
        		isFull <= '0';
        	end if;
     	end if;
     	end if;
    end if;
    end process;
    DO <= outWord;
    full <= isFull;
    empty <= isEmpty;
 end behav;
