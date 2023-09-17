sol=$1
checker=$2

mkfifo pipe_in pipe_out

./$sol < pipe_in 2> error_sol.log  | tee pipe_out &
./$checker < pipe_out 2> error_checker.log | tee pipe_in 

echo "------------------- Error ------------------"
cat error_sol.log
echo "------------------- Error Checker ------------------"
cat error_checker.log
rm error_sol.log
rm error_checker.log
rm pipe_in
rm pipe_out
