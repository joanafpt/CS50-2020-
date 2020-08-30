-- write a SQL query to list the titles of the five highest rated
--movies (in order) that Chadwick Boseman
--starred in, starting with the highest rated.


--SELECT DISTINCT(title)
--FROM movies
--INNER JOIN stars, people, ratings
--WHERE movies.id = stars.movie_id
--AND stars.person_id = people.id
--AND name = "Chadwick Boseman"
--ORDER BY ratings.rating
--LIMIT 5;
------------------------------------

SELECT movies.title
FROM movies
JOIN ratings
ON movies.id = ratings.movie_id
WHERE id
IN (SELECT movie_id
FROM stars
WHERE person_id =
(SELECT id
FROM people
WHERE name ="Chadwick Boseman"))
ORDER BY ratings.rating
DESC LIMIT 5