--write a SQL query to list the names
--of all people who have directed a movie
--that received a rating of at least 9.0.


--name from people
--where people id == directors.people.id

--movied id do directirs == movie-id dos ratings where
--ratings >= 9


SELECT DISTINCT name FROM people
JOIN directors
JOIN ratings
WHERE people.id = directors.person_id AND
ratings.movie_id = directors.movie_id AND
ratings.rating >= 9.0;
