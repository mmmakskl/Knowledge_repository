LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY videomem_bhv IS
	PORT( 
		DATA: IN std_logic_vector(7 downto 0);
		CLK: IN std_logic;		
		KKS: IN std_logic_vector(7 downto 0);
		Query: IN std_logic;
		Q: OUT std_logic_vector(7 downto 0);
		Get: OUT std_logic;
		Synchro: OUT std_logic
		);
END videomem_bhv;

ARCHITECTURE behaviour OF videomem_bhv IS
	type MEM is array (7 downto 0) of std_logic_vector(7 downto 0);
	SIGNAL pixel: MEM;
	SIGNAL sGet : std_logic;

BEGIN
	PROCESS(CLK)
		variable count: integer;
	BEGIN
		IF (CLK'event and CLK = '1') THEN
			count := count + 1; 
			IF count = 8 THEN
				sGet <= '0';
				count := 1;
			END IF;
			IF (KKS = pixel(7)) THEN
				count := 1;
				Synchro <= '1';
			ELSE
				Synchro <= '0';
			END IF;

			for i in 6 downto 0 loop
	      		pixel(i+1) <= pixel(i);
	    	end loop;

			IF ( (Query = '1') and (KKS = pixel(7)) ) or (sGet = '1') THEN
				IF (sGet = '0') THEN
					sGet <= '1';
				END IF;
				pixel(0) <= DATA;
			ELSE
				pixel(0) <= pixel(7);
			END IF;
		END IF;
	END PROCESS;
	Get <= sGet;
	Q <= pixel(7);
END behaviour;

