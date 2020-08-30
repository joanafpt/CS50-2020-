--Your query should output a table with a single column and a single row (plus optional header)
--containing Emma Stone’s birth year.

SELECT birth FROM people WHERE name = 'Emma Stone' OR name = 'EMMA STONE' OR name= 'emma stone';