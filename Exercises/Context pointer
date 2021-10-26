typedef struct {
  const char *text;
  int position;
} text_reader_ctx;

void text_reader_init(text_reader_ctx *ctc, const char *str){
    ctc->position = 0;
    ctc->text = str;
}

int text_reader_read(text_reader_ctx *ctx, char *buffer, int size) {
    if (ctx->text[ctx->position] == '\0') {
        return 0; // to indicate end of buffer
    }
    int i = 0;
    while (ctx->text[ctx->position] != '\0' && i < size - 1 && ctx->text[ctx->position] != '\n') {
        buffer[i] = ctx->text[ctx->position];
        ctx->position++;
        i++;
    }
    // newline character is included in the count
    if (ctx->text[ctx->position] == '\n') {
        buffer[i] = '\n';
        ctx->position++;
        i++;
    }
    buffer[i] = '\0';
    return (int)strlen(buffer);
}
