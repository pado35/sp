// DO_WHILE = do STMT while (E);
void DO_WHILE() {
    // 生成兩個標籤，用於循環開始和結束
    int doBegin = nextLabel(); // 取得新的標籤，用於標記循環開始位置
    int doEnd = nextLabel();   // 取得新的標籤，用於標記循環結束位置
    
    // 輸出循環開始標籤
    emit("(L%d)\n", doBegin);  // 打印標籤，表示循環開始
    
    // 跳過 'do' 關鍵字
    skip("do");
    
    // 解析並執行循環體
    STMT();
    
    // 跳過 'while' 關鍵字
    skip("while");
    
    // 跳過 '('
    skip("(");
    
    // 解析條件表達式
    int e = E();
    
    // 如果條件成立，跳回循環開始位置
    emit("if T%d goto L%d\n", e, doBegin);  // 如果條件成立，跳回循環開始位置
    
    // 跳過 ')'
    skip(")");
    
    // 跳過 ';'
    skip(";");
    
    // 輸出循環結束標籤
    emit("(L%d)\n", doEnd);  // 打印標籤，表示循環結束
}
