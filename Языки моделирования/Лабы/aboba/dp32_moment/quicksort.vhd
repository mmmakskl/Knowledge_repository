LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
use work.sort_types.all;

ENTITY quicksort_nice_try IS
  PORT (
    clk : IN STD_LOGIC;
    data_in : IN memory;
    data_out : OUT memory
  );
END quicksort_nice_try;

ARCHITECTURE behav OF quicksort_nice_try IS
  PROCEDURE Quicksort(
    a : INOUT memory;
    b : INTEGER;
    e : INTEGER) IS
    VARIABLE l, r : INTEGER;
    VARIABLE piv, temp : INTEGER;
  BEGIN
    l := b;
    r := e;
    piv := to_integer(unsigned(a((l + r)/2)));
    WHILE l <= r LOOP
      WHILE to_integer(unsigned(a(l))) < piv LOOP
        l := l + 1;
      END LOOP;
      WHILE to_integer(unsigned(a(r))) > piv LOOP
        r := r - 1;
      END LOOP;
      IF (l <= r) THEN
        temp := to_integer(unsigned(a(r)));
        a(r) := a(l);
        a(l) := STD_LOGIC_VECTOR(to_unsigned(temp, 8));
        r := r - 1;
        l := l + 1;
      END IF;
    END LOOP;
    IF (b < r) THEN
      Quicksort(a, b, r);
    END IF;
    IF (e > l) THEN
      Quicksort(a, e, l);
    END IF;
  END Quicksort;
  SHARED VARIABLE mem : memory;
BEGIN
  PROCESS (clk)
  BEGIN
    if (rising_edge(clk)) then
      mem := data_in;
      Quicksort(mem, 0, 8);
      data_out <= mem;
    end if;
  END PROCESS;
END behav;
