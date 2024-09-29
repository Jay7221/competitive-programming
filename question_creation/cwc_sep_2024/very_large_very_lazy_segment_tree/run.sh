for i in {0..10}
do
    cp "solution_input$i.txt" "testcases/in$i.txt"
    cp "solution_output$i.txt" "testcases/out$i.txt"
done

echo "Done preparing testcases"
