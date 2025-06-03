library ieee;
use ieee.std_logic_1164.all;

ENTITY lifo_bhv IS
	port (
		 DATA_IN : in std_logic_vector(7 downto 0);
		 WR, RD, Reset: in std_logic;
		 CLK: in std_logic;
   	     DATA_OUT : out std_logic_vector(7 downto 0);
		 Full, Empty : out std_logic;
		 COUNT : out integer
	);
END lifo_bhv;

ARCHITECTURE behav of lifo_bhv is
TYPE numArray is array (0 to 7) of std_logic_vector(7 downto 0);
SIGNAL outElement : std_logic_vector(7 downto 0);
SIGNAL lifo : numArray;
SIGNAL isEmpty, isFull: std_logic;
SIGNAL scount : integer := 0;
BEGIN
	PROCESS(CLK, Reset)
    	variable counter : integer range 0 to 8 := 0;
	BEGIN
    	IF (Reset = '1') THEN
      		counter := 0;
			scount <= counter;
			isFull <= '0';
	     	isEmpty <= '1';
    	ELSIF (CLK'event and CLK = '1') THEN
	    		IF (WR = '1' and counter < 8) THEN 			
	        		lifo(counter) <= DATA_IN;
	        		counter := counter + 1;
					scount <= counter;
	      		END IF;
	
	   			IF(RD = '1' and counter > 0) THEN 
	   				counter := counter - 1;
					scount <= counter;
	       			outElement <= lifo(counter); 
	     		END IF;
				
	     		IF counter = 8 THEN
	     			isFull <= '1';
	     			isEmpty <= '0';
	     		ELSIF counter = 0 THEN
	     			isFull <= '0';
	     			isEmpty <= '1';
	     		ELSE
	     			isFull <= '0';
	     			isEmpty <= '0';
	     		END IF;
    	END IF;
    END PROCESS;
    DATA_OUT <= outElement;
    Full <= isFull;
    Empty <= isEmpty;
	COUNT <= scount;
 END behav;

