// Sample Program for COMP1511

// Read a list of driving licences from one file
// and a list of speeding incidents from another file;
// then print an infringement notice for each speeding incident.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LICENCE  300
#define MAX_SPEEDING 500
#define MAX_PLATE     10
#define MAX_NAME      20

typedef struct date_time date_time_t;
typedef struct licence   licence_t;
typedef struct speeding  speeding_t;

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
int scan_incident(speeding_t *incident, FILE *fp);
int scan_date_time(date_time_t *d, FILE *fp);
void print_date_time(date_time_t date);
void print_notices(speeding_t *spd[], licence_t *licences[]);

// Read a list of driving licences from one file
// and a list of speeding incidents from another file;
// then print an infringement notice for each speeding incident.

int main(int argc, char *argv[]) {
    licence_t  licences[MAX_LICENCE];
    speeding_t incidents[MAX_SPEEDING];
    int n_licences, n_incidents;

    if (argc < 3) {
        printf("Usage: %s <licence_file> <incident_file>\n",argv[0]);
        exit(1);
    }

    FILE *licences_file = fopen(argv[1], "r");
    for (n_licences = 0; n_licences < MAX_LICENCE; n_licences++) {
        if (!scan_licence(&licences[n_licences], licences_file)) {
            break;
        }
    }
    fclose(licences_file);

    FILE *incidents_file = fopen(argv[1], "r");
    for (n_incidents = 0; n_incidents < MAX_LICENCE; n_incidents++) {
        if (!scan_incident(&incidents[n_incidents], incidents_file)) {
            break;
        }
    }
    fclose(incidents_file);

    for (int i = 0; i < n_incidents; i++) {
        for (int j = 0; j < n_incidents; j++) {
            if (strcmp(licences[i].plate, incidents[j].plate) == 0) {
                printf("\n%s", licences[i].name);
                printf("On ");
                print_date_time(incidents[j].when);
                printf("\nyou were found traveling at %1.1f km/h above the speed limit\n", incidents[j].km_over_limit);
            }
        }
    }

    return 0;
}

//   Read a licence_t from the file pointer fp, in this format:
// John Smith
//  JJJ 472
// Mary Brown
//  ABC 123

int scan_licence(licence_t *licence, FILE *fp) {
    if (fgets(licence->name,  MAX_NAME, fp) && fgets(licence->plate, MAX_PLATE, fp)) {
        return 1;
    } else {
        return 0;
    }
}

//   Create a record of a speeding incident
//   and scan the relevant data from the file pointer fp,
//   in this format:
//   2/3/2005 3:45 87.6 JJJ 472

int scan_incident(speeding_t *incident, FILE *fp) {
    if (scan_date_time(&incident->when, fp)
        && fscanf(fp, "%lf", &incident->km_over_limit)
        && fgets(incident->plate, MAX_PLATE, fp)) {
        return 1;
    } else {
        return 0;
    }
}


// Read a date_time from the file pointer fp,
// in the format day/month/year hh:mm
int scan_date_time(date_time_t *d, FILE *fp) {
    return fscanf(fp,"%d/%d/%d %d:%d", &d->day, &d->month, &d->year, &d->hour, &d->minute) == 3;
}

//   Print a date_time in the format
//   day/month/year hh:mm
void print_date_time(date_time_t d) {
    printf("%d/%d/%d %d:%d", d.day, d.month, d.year, d.hour, d.minute);
}
