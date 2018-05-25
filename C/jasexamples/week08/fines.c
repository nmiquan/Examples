// Sample Program for COMP1511

// Deal with speeding incidents:
// - read a list of driving licences from one file
// - read a list of incidents from another file
// - print an infringement notice for each incident

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// data structures for:
// licences, incidents, timestamps

#define MAX_LICENCE  300
#define MAX_SPEEDING 500
#define MAX_PLATE     10
#define MAX_NAME      20

typedef struct date_time date_time_t;
typedef struct licence   licence_t;
typedef struct speeding  incident_t;

struct date_time {
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

struct speeding {
    date_time_t   when;
    double        km_over_limit;
    char          plate[MAX_PLATE];
};

struct licence {
    char plate[MAX_PLATE];
    char name[MAX_NAME];
};

int scan_licence(licence_t  *licence, FILE *fp);
int scan_incident(incident_t *incident, FILE *fp);
int scan_date_time(date_time_t *d, FILE *fp);
void print_date_time(date_time_t date);
int find_owner(licence_t ls[], int nl, char *plate);

int main(int argc, char *argv[])
{
    licence_t  licences[MAX_LICENCE];
    incident_t incidents[MAX_SPEEDING];
    int n_licences, n_incidents;
    FILE *input;
    int  i, j;

    // check command line arguments
    if (argc < 3) {
        printf("Usage: %s LicenceFile IncidentFile\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    // read information on licences
    input = fopen(argv[1], "r");
    if (input == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < MAX_LICENCE; i++) {
        if (!scan_licence(&licences[i], input)) {
            break;
        }
    }
    n_licences = i;
    fclose(input);

    // read information on incidents
    input = fopen(argv[2], "r");
    if (input == NULL) {
        perror(argv[2]);
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < MAX_LICENCE; i++) {
        if (!scan_incident(&incidents[i], input)) {
            break;
        }
    }
    n_incidents = i;
    fclose(input);

    // DEBUGGING
    
    // licences
    printf("\nLicences:\n");
    for (i = 0; i < n_licences; i++) {
        printf("%s is registered to %s\n",
               licences[i].plate,
               licences[i].name);
    }
    // incidents
    printf("\nIncidents:\n");
    for (j = 0; j < n_incidents; j++) {
        print_date_time(incidents[j].when);
        printf(" %0.1lf %s\n",
               incidents[j].km_over_limit,
               incidents[j].plate);
    }

    // for each incident
    for (i = 0; i < n_incidents; i++) {
        double over = incidents[i].km_over_limit;
        char *plate = incidents[i].plate;
        // find matching licence
        j = find_owner(licences, n_licences, plate);
        if (j < 0) {
            printf("Unknown plate %s\n", plate);
        } else {
            printf("\n%s,\n", licences[j].name);
            print_date_time(incidents[i].when);
            printf(" you were found traveling\n");
            printf("at %1.1lf km/h above the speed limit\n", over);
        }
    }

    return EXIT_SUCCESS;
}

// Read a licence record from a file
// Licence records appear in this format:
// John Smith, JJJ 472
// Mary Brown, ABC 123
// John Shepherd, ABK 73Z
// Andrew Taylor, XYY ZZY

int scan_licence(licence_t *licence, FILE *fp)
{
    char line[BUFSIZ];
    if (fgets(line, BUFSIZ, fp) == NULL) {
        return 0;
    }
    int n;
    n = sscanf(line, "%[^,], %[^\n]",
               licence->name, licence->plate);
    return (n == 2);
}

// Read a speeding incident from a file
// Incidents appear in this format:
// 2/3/2005 3:45 87.6 JJJ 472

int scan_incident(incident_t *incident, FILE *fp)
{
    char line[BUFSIZ];
    if (fgets(line, BUFSIZ, fp) == NULL) {
        return 0;
    }
    int n;
    date_time_t *dt = &incident->when;
    n = sscanf(line, "%d/%d/%d %d:%d %lf %[^\n]",
               &dt->day, &dt->month, &dt->year,
               &dt->hour, &dt->minute,
               &incident->km_over_limit,
               incident->plate);
    return (n == 7);
}

// Print a date_time to stdout
// in the format "At hh:mm on day/month/year"
void print_date_time(date_time_t d)
{
    printf("At %02d:%02d on %02d/%02d/%d",
           d.hour, d.minute, d.day, d.month, d.year);
}

// Find owner of licence plate
// Returns index where found, or -1 if not found

int find_owner(licence_t ls[], int nl, char *plate)
{
    int i;
    for (i = 0; i < nl; i++) {
        if (strcmp(ls[i].plate, plate) == 0)
            return i;
    }
    return -1;
}

