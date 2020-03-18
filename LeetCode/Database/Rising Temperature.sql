SELECT W2.Id FROM Weather W1, Weather W2
WHERE W1.Temperature < W2.Temperature AND
DATEDIFF(W2.RecordDate, W1.RecordDate) = 1;
