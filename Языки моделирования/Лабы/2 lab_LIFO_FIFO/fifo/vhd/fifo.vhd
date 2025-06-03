LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY fifo IS
    PORT(
        DATA: IN std_logic_vector(7 downto 0);
        CLK: IN std_logic;
        WR: IN std_logic;
        RD: IN std_logic;
        RESET: IN std_logic;
        OUT_DATA: OUT std_logic_vector(7 downto 0);
        IS_FULL: OUT std_logic;
        IS_EMPTY: OUT std_logic
    );
END fifo;

ARCHITECTURE behaviour OF fifo IS
    TYPE WORDS IS ARRAY (0 TO 15) OF std_logic_vector(7 downto 0);
    SIGNAL fifo_data : WORDS;                     
    SIGNAL wr_ptr : INTEGER RANGE 0 TO 15 := 0;               
    SIGNAL rd_ptr : INTEGER RANGE 0 TO 15 := 0;               
    SIGNAL count : INTEGER RANGE 0 TO 16 := 0;                 
BEGIN
    PROCESS (CLK, RESET)
    BEGIN
        IF (RESET = '1') THEN
            wr_ptr <= 0;
            rd_ptr <= 0;
            count <= 0;
            IS_FULL <= '0';
            IS_EMPTY <= '1';
        ELSIF (CLK'event and CLK = '1') THEN
            IF WR = '1' AND count < 16 THEN
                fifo_data(wr_ptr) <= DATA;
                wr_ptr <= (wr_ptr + 1) MOD 16;
                count <= count + 1;
            END IF;

            IF RD = '1' AND count > 0 THEN
                OUT_DATA <= fifo_data(rd_ptr);
                rd_ptr <= (rd_ptr + 1) MOD 16;  
                count <= count - 1;
            END IF;

            IF count = 16 THEN
                IS_FULL <= '1';
            ELSE
                IS_FULL <= '0';
            END IF;

            IF count = 0 THEN
                IS_EMPTY <= '1';
            ELSE
                IS_EMPTY <= '0';
            END IF;
        END IF;
    END PROCESS;
END behaviour;
