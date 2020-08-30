SELECT title FROM movies
JOIN ratings
WHERE movies.id = ratings.movie_id AND
ratings.rating >= 9.0;