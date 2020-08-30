--write a SQL query to determine the average
--rating of all movies released in 2012


SELECT AVG(rating) FROM ratings
INNER JOIN movies
WHERE id = movie_id AND movies.year = 2012;





