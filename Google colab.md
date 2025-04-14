

In Google Colab, several magic commands (directives) are available to enhance functionality and streamline operations.

Here is a list of commonly used magic commands:

## Line Magics

  | Line Magic       | Description |
  |------------------|------------------------|
  |**`%alias`**      | Create an alias for a magic command.|
  |**`%autocall`**   | Control the behavior of callable objects.|
  |**`%automagic`**  | Toggle automatic calling of magic functions without the `%` prefix.|
  |**`%cd`**         | Change the current working directory.|
  |**`%debug`**      | Activate the interactive debugger.|
  |**`%env`**        | Get, set, or list environment variables.|
  |**`%load_ext`**   | Load an IPython extension.|
  |**`%lsmagic`**    | List all available magic commands.|
  |**`%pip`**        | Install Python packages directly from the notebook.|
  |**`%run`**        | Run a Python script in the current notebook.|
  |**`%timeit`**     | Time the execution of a single statement.|

## Cell Magics
  | Line Magic                  | Description |
  |-----------------------------|------------------------ |
  |**`%%writefile <filename>`** | Write the contents of the cell to a file.|
  |**`%%time`**                 | Time the execution of a cell.|
  |**`%%bash`**                 | Execute cell contents as a Bash script.|
  |**`%%html`**                 | Render HTML content in the output cell.|
  |**`%%markdown`**             | Render Markdown content in the output cell.|
  |**`%%bigquery`**             | Run BigQuery SQL queries (requires loading BigQuery extension).|
  |**`%%palm`**                 | Interact with PaLM API for generative AI tasks (requires loading specific extension).|

These commands help manage workflow, run scripts, and interact with external services directly from within a Colab notebook.

Citations:\
[1] https://ipython.readthedocs.io/en/stable/interactive/magics.html \
[2] https://www.youtube.com/watch?v=bNpb8RDbF3w\
[3] https://ai.google.dev/palm_docs/notebook_magic\
[4] https://cloud.google.com/python/docs/reference/bigquery/latest/magics\
[5] https://www.kaggle.com/code/matinmahmoudi/complete-guide-to-magic-commands-a-to-z