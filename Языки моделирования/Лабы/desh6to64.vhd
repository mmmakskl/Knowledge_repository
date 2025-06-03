-- Decryptor 6 -> 64.

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY dec6to64 IS
    PORT (
        x : IN STD_LOGIC_VECTOR(5 DOWNTO 0);
        enable : IN STD_LOGIC;
        f : BUFFER STD_LOGIC_VECTOR(63 DOWNTO 0));
END dec6to64;

ARCHITECTURE behav OF dec6to64 IS
    COMPONENT dec3to8
        PORT (
            a : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
            en : IN STD_LOGIC;
            q : OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
    END COMPONENT;

    SIGNAL enable_signal : STD_LOGIC_VECTOR(7 DOWNTO 0);

BEGIN
    u1 : dec3to8
    PORT MAP(x(5 DOWNTO 3), enable, enable_signal);
    u2 : dec3to8
    PORT MAP(x(2 DOWNTO 0), enable_signal(0), f(7 DOWNTO 0));
    u3 : dec3to8
    PORT MAP(x(2 DOWNTO 0), enable_signal(1), f(15 DOWNTO 8));
    u4 : dec3to8
    PORT MAP(x(2 DOWNTO 0), enable_signal(2), f(23 DOWNTO 16));
    u5 : dec3to8
    PORT MAP(x(2 DOWNTO 0), enable_signal(3), f(31 DOWNTO 24));
    u6 : dec3to8
    PORT MAP(x(2 DOWNTO 0), enable_signal(4), f(39 DOWNTO 32));
    u7 : dec3to8
    PORT MAP(x(2 DOWNTO 0), enable_signal(5), f(47 DOWNTO 40));
    u8 : dec3to8
    PORT MAP(x(2 DOWNTO 0), enable_signal(6), f(55 DOWNTO 48));
    u9 : dec3to8
    PORT MAP(x(2 DOWNTO 0), enable_signal(7), f(63 DOWNTO 56));
END behav;

CONFIGURATION con OF dec6to64 IS
    FOR behav
        FOR u1, u2, u3, u4, u5, u6, u7, u8, u9 : dec3to8
            USE ENTITY work.dec3to8(behavior);
        END FOR;
    END FOR;
END con;
