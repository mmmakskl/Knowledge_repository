LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY my_func IS
PORT (
    D: IN std_logic;
    CLK: IN std_logic;
    Q: OUT std_logic
);
END my_func;

ARCHITECTURE behav OF my_func IS
    SIGNAL Q_OUT : std_logic := '0';
    SIGNAL should_output_one : std_logic := '0';
BEGIN
    PROCESS(CLK)
    BEGIN
        IF (CLK'event AND CLK = '1') THEN
            IF (should_output_one = '1') THEN
                Q_OUT <= '0';
                should_output_one <= '0';
            ELSIF (D = '0' AND Q_OUT = '1') THEN
                should_output_one <= '1';
				Q_OUT <= '1';
            ELSIF (D = '1') THEN
                Q_OUT <= '1';
            END IF;
        END IF;
    END PROCESS;

    Q <= Q_OUT;
END behav;
