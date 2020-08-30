---write a SQL query to list the names of all people who starred in a movie released in 2004,
---ordered by birth year.


--SELECT COUNT(DISTINCT name) FROM people
--INNER JOIN stars -- inner join lines separated
--INNER JOIN movies -- inner join lines separated
--WHERE people.id = stars.person_id AND stars.movie_id = movies.id
--AND movies.year = 2004
--ORDER BY birth ASC;


SELECT name FROM people
WHERE id IN (
SELECT DISTINCT person_id
FROM stars JOIN movies ON stars.movie_id = movies.id
WHERE movies.year = 2004)
ORDER BY birth ASC;