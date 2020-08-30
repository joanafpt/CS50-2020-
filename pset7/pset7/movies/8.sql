--write a SQL query to list the names of all people who starred in Toy Story.
--Your query should output a table with a single column for the name of each person.
--You may assume that there is only one movie in the database with the title Toy Story.

--SELECT title, movie_id FROM stars
--INNER JOIN movies
--WHERE movies.title = "Toy Story" AND movies.id = stars.movie_id;


SELECT name FROM people
INNER JOIN stars -- inner join lines separated
INNER JOIN movies -- inner join lines separated
WHERE people.id = stars.person_id AND stars.movie_id = movies.id
AND movies.title = "Toy Story";


