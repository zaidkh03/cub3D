#include "cub3d.h"

static void trim_newline(char *line)
{
    int len;

    if (!line)
        return ;
    len = ft_strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
}

static char *skip_spaces(char *line)
{
    while (*line == ' ' || *line == '\t')
        line++;
    return (line);
}

static int  handle_texture(t_parse *parse, char *line)
{
    if (!ft_strncmp(line, "NO", 2) && (line[2] == ' ' || line[2] == '\t'))
    {
        set_texture_path(parse, TEX_NO, line + 2);
        return (1);
    }
    if (!ft_strncmp(line, "SO", 2) && (line[2] == ' ' || line[2] == '\t'))
    {
        set_texture_path(parse, TEX_SO, line + 2);
        return (1);
    }
    if (!ft_strncmp(line, "WE", 2) && (line[2] == ' ' || line[2] == '\t'))
    {
        set_texture_path(parse, TEX_WE, line + 2);
        return (1);
    }
    if (!ft_strncmp(line, "EA", 2) && (line[2] == ' ' || line[2] == '\t'))
    {
        set_texture_path(parse, TEX_EA, line + 2);
        return (1);
    }
    return (0);
}

static int  handle_color(t_parse *parse, char *line)
{
    if (line[0] == 'F' && (line[1] == ' ' || line[1] == '\t'))
    {
        set_color_value(parse, 0, line + 1);
        return (1);
    }
    if (line[0] == 'C' && (line[1] == ' ' || line[1] == '\t'))
    {
        set_color_value(parse, 1, line + 1);
        return (1);
    }
    return (0);
}

static void append_map_line(t_parse *parse, const char *line)
{
    char    **new_map;
    int     i;

    new_map = (char **)ft_calloc(parse->map_size + 2, sizeof(char *));
    if (!new_map)
        fatal_parse(parse, "Memory allocation failed");
    i = 0;
    while (i < parse->map_size)
    {
        new_map[i] = parse->map_lines[i];
        i++;
    }
    new_map[i] = ft_strdup(line);
    if (!new_map[i])
    {
        free(new_map);
        fatal_parse(parse, "Memory allocation failed");
    }
    free(parse->map_lines);
    parse->map_lines = new_map;
    parse->map_size++;
}

static void parse_line(t_parse *parse, char *line)
{
    char    *ptr;

    trim_newline(line);
    if (!parse->map_started)
    {
        if (is_line_empty(line))
            return ;
        ptr = skip_spaces(line);
        if (handle_texture(parse, ptr) || handle_color(parse, ptr))
            return ;
        parse->map_started = 1;
    }
    if (is_line_empty(line))
        fatal_parse(parse, "Empty line inside map");
    append_map_line(parse, line);
}

static void parse_init(t_parse *parse)
{
    int i;

    i = 0;
    while (i < 4)
    {
        parse->tex[i] = NULL;
        i++;
    }
    parse->colors[0] = -1;
    parse->colors[1] = -1;
    parse->map_lines = NULL;
    parse->map_size = 0;
    parse->map_started = 0;
}

static void ensure_config(t_parse *parse)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (!parse->tex[i])
            fatal_parse(parse, "Missing texture identifier");
        i++;
    }
    if (parse->colors[0] == -1 || parse->colors[1] == -1)
        fatal_parse(parse, "Missing color identifier");
    if (parse->map_size == 0)
        fatal_parse(parse, "Missing map data");
}

int parse_file(t_cub *cub, const char *path)
{
    t_parse parse;
    int     fd;
    char    *line;

    parse_init(&parse);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        fatal_parse(&parse, "Cannot open map file");
    line = get_next_line(fd);
    while (line)
    {
        parse_line(&parse, line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    ensure_config(&parse);
    validate_map(&parse);
    build_map(cub, &parse);
    return (1);
}
